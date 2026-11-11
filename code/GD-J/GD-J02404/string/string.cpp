#include<bits/stdc++.h>
using namespace std;
long long n,num=0,a[200200],l,r;
char b[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=0;
	r=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(;;){
		if(l>=r){
			break;
		}
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				num+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				num+=a[l];
				l++;
			}else{
				num+=a[l];
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}
