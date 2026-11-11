#include<bits/stdc++.h>
using namespace std;
struct shu{
	int ge;
	char zi;
}a[200005];
string s;
long long n;
long long m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].ge>>a[i].zi;
	}
	
	for(long long j=n;j>=1;){
		for(int i=1;i<=n;i++){
			if(i==j){
				cout<<m;
				return 0;
			}
		long long w=a[i].ge;
				while(w>0){
				if(i==j){
				cout<<m;
				return 0;
			}	
				if(a[j].zi!=a[i].zi){
					if(i==j){
				cout<<m;
				return 0;
			}	
					if(a[j].ge>w){
						a[j].ge-=w;
						m+=w;
						w=0;
					}
					else if(a[j].ge<=w){
						w-=a[j].ge;
						m+=a[j].ge;
						j--;
						if(i==j){
				cout<<m;
				return 0;
			}	
					}
				}
				else j--;
			}
		}
	}
	cout<<m<<endl;			
		return 0;
}
