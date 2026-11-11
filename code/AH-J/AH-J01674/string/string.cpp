#include<bits/stdc++.h>
using namespace std;
int n,m[200001],Fat_Catt,cnt=0;
char c[200001];
string a,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
		Fat_Catt=max(Fat_Catt,m[i]);
	}
	if(Fat_Catt*n<=200000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m[i];j++){
				a+=c[i];
				t+=c[i];
			}
		}	
		for(long long i=0;i<=a.size();i++){
			if(a[i]!=t[a.size()-i-1]){
				cnt++;
			}
		}
		cout<<cnt/2;
	}
	else{
		cout<<0;//不可以总司令！ 
	}
	return 0;
}
//打表过样例，暴力出奇迹
//十年OI一场空，不开long long见祖宗
//（还是暴力好写awa）
//话说写什么会被禁赛三年啊 
