#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500000+10]={0};
long long s[500000+10]={0},t=0,f[500000+10]={0};
long long sum[500000+10]={0};
long long q[500000+10]={0};
bool flag=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i!=1 && a[i]<a[i-1]){
			flag=false;
		}
		q[a[i]]++;
	}
	if(n<=9000){
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=i;j<=n;j++){
				if(f[a[j]]==0 || (s[f[a[j]]]!=a[j] || f[a[j]]>t)){
					t++;
					f[a[j]]=t;
					s[t]=a[j];
				}else{
					t=f[a[j]];
				}
			}
			for(int j=1;j<=t;j++){
				sum[s[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout << sum[i] << ' ';
		}
		return 0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(i!=1){
				q[a[i-1]]--;
				if(q[a[i-1]]==0){
					sum[a[i-1]]-=(n-i+1);
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout << sum[i]+n << ' '; 
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0 || (s[f[a[j]]]!=a[j] || f[a[j]]>t)){
				t++;
				f[a[j]]=t;
				s[t]=a[j];
			}else{
				t=f[a[j]];
			}
		}
		for(int j=1;j<=t;j++){
			sum[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << ' ';
	}
	return 0;
}
