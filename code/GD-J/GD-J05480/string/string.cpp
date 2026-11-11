#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,a[N],s,cnt;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	long long x=0,y=0,i=1,j=n;
	while(x<=s/2&&y<=s/2){
		if(x<=y){
			x+=a[i++];
		}
		else if(y<x){
			y+=a[j--];
		}
		if(x>s/2){
			x-=a[i-1];
			break;
		}
		if(y>s/2){
			y-=a[j+1];
		}
		while(b[i]==b[j]){		
			if(x<y){
				x+=a[i++];
			}
			else if(y<x){
				y+=a[j--];
			}
		}
		while(x<y){
			x+=a[i++];
			if(b[i]!=b[j]){
				if(x<=y){
					cnt+=a[i-1];
				}
				else cnt+=x-y;
			}
		} 
		while(x>y){
			y+=a[j--];
			if(b[i]!=b[j]){
				if(x>=y){
					cnt+=a[j=1];
				}
				else cnt+=y-x;
			}
		} 
	}
	if(x<y){
		x+=a[i++];
		if(b[i]!=b[j]){
			if(x<=y){
				cnt+=a[i-1];
			}
			else cnt+=x-y;
		}
	}
	else if(x>y){
		y+=a[j--];
		if(b[i]!=b[j]){
			if(x>=y){
				cnt+=a[j+1];
			}
			else cnt+=y-x;
		}
	}
	cout<<cnt;
	return 0;
} 
