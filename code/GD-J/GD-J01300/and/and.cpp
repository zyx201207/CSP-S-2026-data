#include<iostream>
#include<vector>
using namespace std;
int sum=0,n,p;
vector<int> a;
vector<int> d(n,0);
void check(int t,int c){
	if(t==0){
		if(c>sum){
			sum=c;
		}
		return;
	}
	
	for(int i=0;i<n;i++){
		if(d[i]==0){
			c=c&a[i];
			d[i]=1;
			check(t-1,c);
			d[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>p;
	
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a.push_back(b);
   }
   for(int i=0;i<n;i++){
   	d[i]=1;
   	check(p-1,a[i]);
   	d[i]=0;
   }
   cout<<sum;
   return 0;
}

