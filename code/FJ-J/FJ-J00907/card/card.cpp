#include<bits/stdc++.h>
using namespace std;
int a[500001],t[300001],ls[500001],cnt[300001];

void sp(int ps,int dq){
	for(int i = ps; i<=dq; i++){
		t[ls[i]]=0;
		ls[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,dq=1;
	cin>> n >> m;
	for(int i = 1; i<=n; i++){
		cin>> a[i];
	}
	for(int i = 1; i<=n; i++){
		dq=1;
		for(int j = i; j<=n; j++){
			if(t[a[j]]!=0){
				int temp=dq;
				sp(t[a[j]],temp);
				dq=temp;
			}else{
				t[a[j]]=dq;
				ls[dq]=a[j];
				dq++;
			}
		}
		for(int j = 1; j<=dq; j++){
			cnt[ls[j]]++;
		}
		for(int j = 1; j<=n; j++){
			ls[j]=0;
		}
		for(int j = 1; j<=m; j++){
			t[j]=0;
		}
	}
	for(int i = 1; i<=m; i++){
		cout<< cnt[i] << " ";
	}
	return 0;
}
