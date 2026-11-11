#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+5;
int cnt[N][35],ans[35];
bool flag[N];
inline int read(){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	int f=0;
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read();
	int k=0;
	for(int i=1;i<=n;i++){
		int x=read();
		int tot=0;
		while(x){
			cnt[i][++tot]=x%2;
			if(cnt[i][tot]){
				ans[tot]++;
				k=max(tot,k);
			}
			x/=2;
		}
	}
	int cj=pow(2,k-1),curr=0;
	for(int i=k;i>=1;i--){
		if(ans[i]>=m){
			for(int j=1;j<=n;j++){
				if(!flag[j]&&!cnt[j][i]){
					flag[j]=1;
					for(int h=1;h<=i-1;h++)if(cnt[j][h])ans[h]--;
				}
			}
			curr+=cj;
		}
		cj/=2;
	}
	cout<<curr;
	return 0;
}
