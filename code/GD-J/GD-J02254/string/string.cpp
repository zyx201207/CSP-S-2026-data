#include<bits/stdc++.h>
using namespace std;

long long n=0, a[200005]={0}, len=0, b[200005]={0}, sum=0, zj=0, ans=0;
char c[200005], d[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int j=1; j<=n; j++){
		cin>>a[j]>>c[j];
		len+=a[j];
	}
	long long pos=0;
	if(len%2==0){
		for(int i=1; i<=n; i++){
			if(pos+a[i]<len/2){
				b[++sum]=a[i];
				d[sum]=c[i];
			}
			else if(pos<len&&pos+a[i]==len/2){
				b[++sum]=a[i];
				d[sum]=c[i];
				zj=sum;
			}
			else if(pos<len/2&&pos+a[i]>len/2){
				b[++sum]=len/2-pos;
				d[sum]=c[i];
				zj=sum;
				b[++sum]=pos+a[i]-len/2;
				d[sum]=c[i];
			}
			else{
				b[++sum]=a[i];
				d[sum]=a[i];
			}
			pos+=a[i];
		} 
	}
	else{
		for(int i=1; i<=n; i++){
			if(pos+a[i]<=len/2){
				b[++sum]=a[i];
				d[sum]=c[i];
			}
			else if(pos<len&&pos+a[i]==len/2){
				b[++sum]=a[i];
				d[sum]=c[i];
				zj=sum;
			}
			else if(pos<=len/2&&pos+a[i]>len/2){
				if(len/2-pos>0){
					b[++sum]=len/2-pos;
					d[sum]=c[i];
				}
				zj=sum;
				if(pos+a[i]>len/2+1){
					b[++sum]=pos+a[i]-len/2-1;
					d[sum]=c[i];
				}
			}
			else{
				b[++sum]=a[i];
				d[sum]=c[i];
			}
			pos+=a[i];
		}
		len--;
	}
	long long wz=sum, yd=0;
	for(int i=1; i<=zj; i++){
		if(b[i]<=b[wz]-yd){
			if(d[i]!=d[wz]){
				ans+=b[i];
			}
			if(b[i]<b[wz]-yd){
				yd+=b[i]; 
			}
			else{
				yd=0;
				wz--;
			}
		}
		else if(b[i]>b[wz]-yd){
			if(d[i]!=d[wz]){
				ans+=b[wz]-yd;
			}
			int sy=b[i]-(b[wz]-yd);
			wz--;
			while(sy>=b[wz]){
				if(d[i]!=d[wz]){
					ans+=b[wz];
				}
				sy-=b[wz];
				wz--;
			}
			if(d[i]!=d[wz]){
				ans+=sy;
			}
			yd=sy;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
