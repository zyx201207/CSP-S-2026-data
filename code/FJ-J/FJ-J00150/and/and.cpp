#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	int a[100005];
	int s[10005][35]={0},ans[35];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			if(a[i]>=pow(2,31-j)){
				a[i]-=pow(2,31-j);
				s[i][31-j]=1;
			}
			cout<<s[i][31-j];
		}cout<<endl;
	}
	int except=0;
	for(int i=1;i<=30;i++){
		if(n-except==m)break;
		int sum=0;//当前位数为1的个数 
		for(int j=1;j<=n;j++){
			if(s[j][0]==2)continue;
			if(s[j][i]==1){
				sum++;
			}
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i]!=1){
					s[j][0]=2;
					except++;
				}
			}
		}
	}
	int f=1;
	for(int i=1;i<=n;i++){
		if(f==1){
			f=0;
			for(int j=1;j<=30;j++){
				ans[j]=s[i][j];
			}
		}else{
			for(int j=1;j<=30;j++){
				if(s[i][j]!=1)ans[j]=0;
			}
		}
	}
	int answer=0;
	for(int i=1;i<=30;i++){
		if(ans[i]==1)
			answer+=pow(2,31-i);
	}
	cout<<answer;
	return 0;
}
