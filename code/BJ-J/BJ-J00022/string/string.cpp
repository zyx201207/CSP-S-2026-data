#include <bits/stdc++.h>
using namespace std;
char c[214514];
int a[214514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cout<<a[i]<<c[i]<<"\n";
		cnt+=a[i];
	}if (cnt%2==1){
		cnt=cnt+1;
	}cnt/=2;
	int xb1=1,xb2=n;

	long long as=0;
	int end=0,h=0;
	for (int i=1;i<=n;i++){
		h+=a[i];
		if (h>=cnt){
			end=i;
			break;
		}
	}//cout<<end;
	while(1){
		//cout<<xb1<<" "<<xb2<<"\n";
		if (a[xb1]==a[xb2]){
			if (c[xb1]!=c[xb2]){
				as+=a[xb1];
			}xb1++,xb2--;
		}else if (a[xb1]<a[xb2]){
			if (c[xb1]!=c[xb2]){
				as+=a[xb1];
			}a[xb2]-=a[xb1];
			xb1++;
		}else if (a[xb1]>a[xb2]){
			if (c[xb1]!=c[xb2]){
				as+=a[xb2];
			}a[xb1]-=a[xb2];
			xb2--;	
		}
		if (xb1>end||xb2<end){
			break;
		}
	}cout<<as;
	return 0;
}