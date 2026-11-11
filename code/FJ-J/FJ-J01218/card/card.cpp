#include<bits/stdc++.h>
using namespace std;
int d[500005],a[500005],h,n,m,z[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		//cout<<i<<endl<<endl;
		for(int j=i;j<=n;j++){
			//cout<<j<<"<<<"<<endl;
			bool in=true;
			int wei;
			for(int y=1;y<=h;y++){
				if(d[y]==a[j]){
					in=false;
					wei=y;
					//cout<<wei<<endl;
					break;
				}
			}
			if(in){
				d[h+1]=a[j];
				h++;
			}
			else{
				//for(int j=1;j<=h;j++){
				//	cout<<d[j]<<" ";
				//}
				//cout<<endl;
				//cout<<wei<<" "<<d[wei]<<endl;;
				for(int y=wei;y<=h;y++){
			//		cout<<d[y]<<" ";
					d[y]=0;
				}
				//cout<<"  "<<"Backspace"<<endl;
				h=wei-1;
				///for(int j=1;j<=h;j++){
				//	cout<<d[j]<<" ";
				//}
				//cout<<endl;
			}
		}
		for(int j=1;j<=h;j++){
			z[d[j]]++;
		}
		//cout<<endl<<endl;
		//for(int j=1;j<=h;j++){
		//	cout<<d[j]<<" ";
		//}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<z[i]<<" ";
	return 0;
}
