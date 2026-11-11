#include<bits/stdc++.h>
using namespace std;
int n,m,tn=0,cnt = 0;
int a[500010];
int t[500010];
int ans[500010];
int number_k = -1;
bool check_(int k){
	for(int i=0;i<tn;i++){
		if(t[i] == k){
			number_k = i;
			return true;
		}
	}
	number_k = -1;
	return false;
}
bool check_num(int k){
	for(int i=0;i<tn;i++){
		if(t[i] == k){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int I=1;I<=n;I++){
		for(int i=I;i<=n;i++){
			if(check_(a[i])){
				for(int l=number_k;l<tn;l++){
					t[l] = 0;
				}
				t[number_k] = a[i];
				tn = number_k+1;
			}else{
				t[tn] = a[i];
				tn++;
				}
		}
		
		for(int l=0;l<tn;l++){
			ans[t[l]]++;
		}
		
		for(int ii=0;ii<=tn;ii++) t[ii] = 0;
	}
	
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
