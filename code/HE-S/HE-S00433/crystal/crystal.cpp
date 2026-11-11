#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[55555555];
long long f[55555555]={0};

void init(){
	cin>>n>>m;
	long long i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
}

void qyj(){
	long long i;
	long long j=0;
	sort(a,a+n);
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]){
			j++;
		}
	}
	f[0] = j+1;
	for(i=1;i<=n;i++){
		for(j=1;j<n;j++){
			if(a[j+1]!=a[j]){
				if(i > (a[j+1]-a[j])){
					f[i] = max(f[i] , f[i-(a[j+1]-a[j])]+1);
					a[j] = a[j+1];
				}
			}
		}
	}
	cout<<f[m];
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	init();
	qyj();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;

//long long n,m;
//long long a[555555];
//long long f[555555]={0};

//void init(){
//	cin>>n>>m;
//	long long i;
//	for(i=0;i<n;i++){
//		cin>>a[i];
//	}
//}
//void qyj(){
//	long long i,j;
//	long long w=m;
//	long long u=n;
//	long long k=0;
//	long long mim=1e18;
//	sort(a,a+n);
//	for(i=0;i<n;i++){
//		for(j=0;j<n-1;j++){
//			if(a[j+1]-a[j] < mim and a[j+1]!=a[j]){
//				mim = a[j+1]-a[j];
//				k=j;
//			}
//			if(w>a[k+1]-a[k]){
//				w-=a[k+1]-a[k];
//				a[j] = a[j+1];
//			}
//		}
//	}
//	long long h=0;
//	for(i=0;i<n-1;i++){
//		if(a[i]==a[i+1]){
//			h++;
//		}
//	}
//	cout<<h;
//}

//int main(){
//	init();
//	qyj();
//	
//	return 0;
//} 
