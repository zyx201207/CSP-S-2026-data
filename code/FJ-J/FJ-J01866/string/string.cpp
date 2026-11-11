#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	int n;
	cin>>n;
	long long s=0;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	long long cnt = 0;
	int x = 1;
	int m=s/2+1;
	while(m>=a[x]){
		m-=a[x];
		x++; 
	}
	if(m>0){
		for(int i=n;i>=x;i--){
		a[i+1]=a[i];
		b[i+1]=b[i];
	    }
		a[x]=m;
		a[x+1]-=m;
	}
	int l = 1;
	int r = n;
	while(s>1 && r>=l){
		if(a[l]>a[r]){
			a[l]-=a[r];
			s-=a[r];
			if(b[l]!=b[r]){
				cnt+=a[r];
			}
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			s-=a[l];
			if(b[r]!=b[l]){
				cnt+=a[l];
			}
			l++;
	    }else{
	    	s-=a[l];
	    	if(b[r]!=b[l]){
				cnt+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
