#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string tentotwo(int num){
	//十进制换字符串二进制
	string str1="",str2="";
	while(num!=0){
		char ch=(num%2)+'0';
		num/=2;
		str1+=ch;
	}
	for(int i=str1.size()-1;i>=0;i--)
	  str2+=str1[i];
	return str2;
}
int twototen(string str){
	//字符串二进制换十进制数字
	int j=1,num=0;
	for(int i=str.size()-1;i>=0;i--){
		int t=str[i]-'0';
		num+=t*j;
		j*=2;
	} 
	return num;
}
int num[N],flag[N],numno=0;//flag:1必不选,numno为不选个数 
string s[N];
int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>num[i],flag[i]=0;
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	  s[i]=tentotwo(num[i]);
	int maxleng=s[n].size();
	for(int i=1;i<=n;i++){
		int nowleng=s[i].size();
		for(int j=1;j<=maxleng-nowleng;j++)
		  s[i]="0"+s[i];
	}
	for(int i=0;i<maxleng;i++){
		int have=0;
		for(int j=n;j>=1;j--){
			if(flag[j]!=1&&s[j][i]=='1')
			  have++;
		}
		if(have>=m)
		  for(int j=n;j>=1;j--)
			if(flag[j]!=1&&s[j][i]=='0')
			  flag[j]=1,numno++;
		if(numno+m==n){
			string ans="111111111111111111111111111111";
			for(int j=1;j<=n;j++){
				if(flag[j]!=1){
					int num=s[j].size();
					for(int i=0;i<30-num;i++)
					  s[j]='0'+s[j];
					for(int i=0;i<30;i++)
					  if(s[j][i]=='0'||ans[i]=='0')
						ans[i]='0';
				}
			}
			cout<<twototen(ans)<<endl;
			return 0;
		}
	}
	string ans="111111111111111111111111111111";
	for(int j=1;j<=n;j++){
		if(flag[j]!=1){
			int num=s[j].size();
			for(int i=0;i<30-num;i++)
			  s[j]='0'+s[j];
			for(int i=0;i<30;i++)
			  if(s[j][i]=='0'||ans[i]=='0')
				ans[i]='0';
		}
	}
	cout<<twototen(ans)<<endl;
	return 0;
}
