#include <bits/stdc++.h>
using namespace std;
long long b[200009],n,c[200009],num,mid,j=1;
int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	char a[200009];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		c[i]+=c[i-1]+b[i];
	}
	mid=(c[n]+1)/2;
	while(1){
		if(c[j]>mid){
			b[j]-=2*(c[j]-mid);
			while(1){
				if(j==n){
					cout<<num;
					return 0;
				}
			    if(a[j]!=a[n]){
		        num+=b[n];
		}
		n--;  
	}
	    }else if(c[n]-b[n]+1<mid){
					b[n]=c[n]-mid;
			while(1){
				if(j==n){
					cout<<num;
					return 0;
				}
			    if(a[j]!=a[n]){
		        num+=b[j];
		}
		j++;
	}
		}else if(j==n || j>n){
			break;	
		}else{
		 if(a[j]!=a[n]){
			num+=min(b[j],b[n]);
		}
			if(b[j]<b[n]){
				j++;
				b[n]-=b[j];
			}else if(b[j]>b[n]){
				n--;
				b[j]-=b[n];
			}else{
			j++;
			n--;
			}
	 }
	    }
    cout<<num;
}

