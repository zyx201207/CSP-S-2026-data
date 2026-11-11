#include <bits/stdc++.h>
using namespace std;
char a[500010];
int dp[500010];
string s,s1;
bool pan(string s,char c){
	for(int i=0;i<s.size();i++)
		if(s[i]==c)return true;
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int jushu=1;jushu<=n;jushu++){
		int k=1;
		s.clear();
		for(int i=jushu;i<=n;i++){//放牌 
			if(pan(s,a[i])==true){//若有重复牌 错了 
				for(int j=i;j>=jushu;j--){//逐个拿牌直到找到最早出现牌 
					if(a[i]==s[j])break;
					else{
						s[j]=' ';
						k--;
					}
				}
			}
			else{//从未出现,存牌 
				s=s+a[i];
				k++;
			}
		}//牌处理完毕
		s1.clear();
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')continue;
			else s1=s1+s[i];
		}//去除空格 
		for(int i=0;i<s1.size();i++){
			dp[s1[i]-'0']++;
		} //按位加出现次数 
		//cout <<s1<<endl;
	}
	for(int i=1;i<=m;i++) cout <<dp[i]<<' ';//输出 
	return 0;
}
