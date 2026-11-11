#include <bits/stdc++.h>
using namespace std;
int N;
const int MAXN=2*100000+10;
string s1=' '+s1;
long long change;
//struct nood{
//	long long len;
//	char zifuchuan;
//}nood s[MAXN];
//void sovle2(){
//	int sum2=0;
//	for(int i=1;i<=N;i++){
//		cin>>s[i].len>>s[i].zifuchuan;
//		sum+=s[i].len;
//	}for(int i=1;i<=(N+1)/2;i++){
//		if(s[i].zifuchuan!=s[N+1-i].zifuchuan){
//			change+=abs(s[i].len-s[N+1-i].len);
//		}
//	}
//}
void sovle1(){
	int sum=0;
	bool flag=true;
	int y1lost;
	int y;
	for(int i=1;i<=N;i++){
		
		string x;
		cin>>y>>x;
		if(i==1) y1lost=y;
		else if (y1lost!=y) flag=0; 
		sum+=y;
		for(int j=1;j<=y;j++){
			s1=s1+x;
		}
	}
	if(flag){
		cout<<y;
	}else {
		int lens1=s1.size();
		for(int i=2;i<(lens1+1)/2;i++){
			if(s1[i]!=s1[(lens1+1)-i]){
				change++;
		}
		}cout<<change;
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	sovle1();
}
