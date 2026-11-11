#include<iostream>
using namespace std;
int a[500005],b[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int head=1,tail=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			for(int l=head;l<=tail;l++){
				if(a[j]==b[l]){
					tail=l-1;
				}
			}
			tail++;
			b[tail]=a[j];
		}
		for(int l=head;l<=tail;l++){
			c[b[l]]++;
		}
		for(int l=head;l<=tail;l++){
			b[i]=0;
		}
		tail=0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0)cout<<c[i]<<" ";
	}
	return 0;
}
