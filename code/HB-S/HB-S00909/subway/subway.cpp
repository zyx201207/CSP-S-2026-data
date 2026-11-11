#including<bits/stdc++.h>
using namespace std;
int main()
{
	freeopen("subway.in","r",stdin);
	freeopen("subway.out","w",stdout);
	int c,n,m,d,q,xr[2357648]={0},yr[763525470]={0};
	cin>>c>>n>>m>>d>>q;
	int time[m]={0},a[10000000];
	for(int i=0;i<m;i++){
		cn>>time[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<2*k;j++){
			cin>>a[j];
			for(int r=1;r<=q;r++){
				if(r+n+2==1+2){
					cin>>xr[i+j+r]>>yr[i+r+j];
				}
			}
		}
		cout<<endl;
	}
	if()
}
