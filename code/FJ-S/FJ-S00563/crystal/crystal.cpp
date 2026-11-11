#include<bits/stdc++.h>
using namespace std;
long long a[500001],m,number=0,b[500001];
int n,ans=0;
void guibin(int left,int right){
	if(left>=right) return;
	int mid=(left+right)/2;
	guibin(left,mid);
	guibin(mid+1,right);
	int lz=left,rz=mid+1;
	for(int i=left;i<=right;i++){
		if((a[lz]<=a[rz]&&lz<=mid)||rz>right){
			b[i]=a[lz];
			lz++;
		}
		else{
			b[i]=a[rz];
			rz++;
		}
	}
	for(int i=left;i<=right;i++){
		a[i]=b[i];
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	guibin(1,n);
	for(int i=1;i<=n-1;i++){
		a[i]=a[i+1]-a[i];
	}
	a[n]=0;
	for(int i=n;i>=1;i--){
		a[i]+=a[i+1];
	}
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1]) continue;
		number=0;
		int j=i,rans=0;
		while(number<=m&&j>0){
			j--;
			number+=a[j]-a[i];
			rans++;
		}
		if(number>m) rans--;
		ans=max(rans,ans);
		if(j<0) break;
	}
	cout <<ans;
}
