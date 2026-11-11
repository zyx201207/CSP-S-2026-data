#include <bits/stdc++.h>
using namespace std;
long long n;
void ad(long long x,long long y){
		int ansx[30];
		int cntx=0;
		while(x!=0){
			ansx[cntx]=x%2;
			x/=2;
			cntx++;
		}
		int ansy[30];
		int cnty=0;
		while(y!=0){
			ansy[cnty]=y%2;
			y/=2;
			cnty++;
		}

		int c[30]={0};
		for(int i=0;i<30;i++){
			if(ansx[i]==1&&ansy[i]==1){
				c[i]=1;
			}
			else c[i]=0;
		}
		long long aser=0;
		
		for(int i=0;i<20;i++){
			aser+=c[i]*pow(2,i);
		}
		cout<<aser;
	}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long numbers[n+1]={0};
	for(long long i=0;i<n;i++){
		cin>>numbers[i];
		
	}
	sort(numbers,numbers+n);
	
	if(m==1){
		cout<<numbers[n-1];
		return 0;
	}
	if(m==2){
		ad(numbers[n-2],numbers[n-1]);
		return 0;
	}
	
	

	
	return 0;
}
