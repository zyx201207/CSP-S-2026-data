#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],t[300005],t1[300005],r;
struct gg{
	int d;
	int l;
}a[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].d);
		if(t[a[i].d]==1){
			for(int j=a[i].l+1;j<=r;j++){
				t[b[j]]=0;
			}
			r=a[i].l;
		}else{
			a[i].l=r+1;
			r++;
			b[r]=a[i].d;
		}
		t[a[i].d]=1;
		for(int j=1;j<=r;j++){
		//	cout<<b[i]<<" ";
			t1[b[i]]++;
		}
		//cout<<a[i].l;
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<t1[i]<<" ";
	}
	return 0;
}
