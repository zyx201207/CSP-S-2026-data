#include <bits/stdc++.h> 
using namespace std;

struct a{
	int n;
	int m;
};
int a[200005];
bool cmp(int n,int m){
	return a[n] <= a[m];
}
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m,res=0,sum=1;
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort (a+1,a+n+1,cmp);
	for (int i=0;i<n;i++){
	    if (a[i]%2==0){
	    	 if(a[i+1]%2==0){
	    		res+=pow(2,sum);
			}
		}
		if (a[i]%2==1){
			int r=1;
	    	 if(a[i+1]%2==1){
	    		res+=1;
	    		r++;
	    		if(r>1){
	    			res+=pow(2,sum);
				}
			}
		}
		a[i]/=2;
		sum++;
	}
	cout << sum; 
	return 0;
}
