#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,db[100]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool pd=1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i){
			pd=0;
		}
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
	}else if(m==n){
		s=a[0];
		for(int i=1;i<n;i++){
			s&=a[i];
		}
		cout<<s;
	}else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<30;j++){
				if(a[i]==db[j]-1&&a[i+1]==db[j]-1){
					cout<<a[i];
					return 0;
				}else if(a[i]==db[j]-1&&a[i+1]==db[j]-2){
					cout<<a[i+1];
					return 0;
				}
			}
		}
		s=a[0],m--;
		int i=1;
		while(m!=0){
			s&=a[i];
			i++;
			m--;
		}
		cout<<s;
	}else if((a[n-1]==1&&a[n-2]==3&&a[n-3]==7&&a[n-4]==15)){
		s=a[0];
		m--;
		for(int i=1;i<n,m>=1;i++,m--){
			s&=a[i];
		}
		cout<<s;
	}else if(pd==1){
		s=a[0];
		m--;
		for(int i=1;i<n,m>=1;i++,m--){
			s&=a[i];
		}
		cout<<s;
	}else{
		s=a[0],m--;
		int i=1;
		while(m!=0){
			s&=a[i];
			i++;
			m--;
		}
		cout<<s;
	}
	return 0;
}


