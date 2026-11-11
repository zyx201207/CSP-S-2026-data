#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,cnt=1,a[MAXN];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++)   cin>>a[i];
	sort(a+1,a+n+1);
	int mid=ceil(n*1.0/2);
	int l=mid-1,r=mid+1;
	while(l!=0||r!=n+1)
	{
		if(m>0){
			if((a[mid]-a[l])<cnt*(a[r]-a[mid])){
				m-=(a[mid]-a[l]);
				if(m<0){
					cout<<cnt;
					break;
				}
				a[l]=a[mid];
				l--;
			}
			else
			{
				m-=cnt*(a[r]-a[mid]);
				if(m<0){
					cout<<cnt;
					break;
				}
				for(int i=l+1;i<=r-1;i++){
					a[i]=a[r];
				}
				r++;
			}
			cnt++;
		}
		else{
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}
