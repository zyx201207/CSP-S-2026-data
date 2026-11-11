//GZ-J00179 遵义市红花岗区第十三小学 郭璟岩
#include <bits/stdc++.h>
using namespace std;
int a[5005],q[5005],t[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t2=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=t2;k++){
				if(q[k]==a[j]){
					t2=k;
					break;
				}
			}
			t2++;
			q[t2]=a[j];
		}
		for(int i=1;i<=t2;i++){
			t[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}

