#include<bits/stdc++.h>
using namespace std;

int n=0, m=0, sl[40]={0}, ans[40]={0}, a[200005]={0};
bool e[200005][40], ys[200005]={0};

void ejz(int x, int k){
	int i=1;
	while(x>0){
		e[k][i]+=x%2;
		sl[i]+=x%2;
		x/=2;
		i++;
	}
	return;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		ys[i]=1;
		ejz(a[i], i);
	}
	for(int i=30; i>0; i--){
		if(sl[i]>=m){
			ans[i]=1;
			for(int j=1; j<=n; j++){
				if(e[j][i]==0&&ys[j]==1){
					ys[j]=0;
					for(int k=1; k<=30; k++){
						sl[k]-=e[j][k];
					}
				}
			}
		}
		else{
			ans[i]=0;
		}
	}
	int an=0, pw=1;
	for(int i=1; i<=30; i++){
		an+=ans[i]*pw;
		pw*=2;
	}
	cout<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
