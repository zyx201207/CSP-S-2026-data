#include<bits/stdc++.h>
using namespace std;
long long int n,sum=0,r,l,a[200005];
char s[200005];
void cha(){

	int x=a[l],y=a[r];
	if(s[l]!=s[r]){
		if(x>y){
			a[l]=x-y;
			a[r]=0;
			sum+=y;
			r--;
		}else if(x<y){
			a[r]=y-x;
			a[l]=0;
			sum+=x;
			l++;
		}else{
			sum+=x;
			r--;
			l++;
			if(l>r){
				l=r;
			}
		}
	}else{
		if(x>y){
			a[l]=x-y;
			a[r]=0;
			r--;
			if(l>r){
				l=r;
			}
		}else if(x<y){
			a[r]=y-x;
			a[l]=0;
			l++;
			if(l>r){
				l=r;
			}
		}else{
			r--;
			l++;
			if(l>r){
				l=r;
			}
		}
		
		
	}
}
int main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	l=0;
	r=n-1;
	while(r>l){
		cha();
	}
//	cout<<S;
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" "<<s[i]<<" ";
//	}
	cout<<sum;
	return 0;
}

