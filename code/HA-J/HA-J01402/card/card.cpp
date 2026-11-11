#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],t[300005],key=1,l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		l=q;
		key=0;
		for(int i=q;i<=n;i++){
			for(int j=i-1;j>=l;j--){
				if(a[i]==a[j]){
					l=i;
					break;
				}
			}
			if(key==1)break;
		}
		for(int i=n;i>=l;i--){
			t[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
