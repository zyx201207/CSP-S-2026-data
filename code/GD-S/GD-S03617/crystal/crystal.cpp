#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[5*N+5],b[5*N+5];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	
	//要使水晶尽可能多，那么操作次数就要尽可能少 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<i<<' ';
	}
//	return 0;
	sort(a+1,a+1+n,cmp);
//	cout<<a[1]<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<i<<' '<<a[i]<<'  ';
//	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long maxn=1000000000005,maxflag=-1,maxsize=1;
//	while(m>0){
		int nown=2,nowmax=b[2];
		maxn=b[2],maxsize=2,maxflag=1;
		for(int i=2;i<n;i++){
			if(b[i+1]>=b[i] || b[i+1]==0){
				if(m-nowmax<b[i+1]*nown){
//					cout<<"br";
					break;
				}
				nowmax+=b[i+1]*nown;
				nown++;
//				cout<<"ok";
				
				if(nown>maxsize/* || (nown==maxsize && nowmax<maxn)*/){
//					cout<<"pl";
					maxsize=nown;
					maxn=nowmax;
					maxflag=i-nown+2;
				}
			}else{
				nown=1;
			}
		}
//	}
//	for(int i=maxflag;i<maxsize;i++){
//		cout<<i<<' '<<a[i]<<"  ";
//	}
	cout/*<<maxflag<<' '*/<<maxsize;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
