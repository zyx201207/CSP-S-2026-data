#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int max1=0;
	for(long long i=a[0];i<a[n-1];i++){
	    long long b[200005]={0};
		int j;
		    for(j=0;j<n;j++){
		    b[j]=i-a[j];
		    if(b[j]<0){
		    	b[j]=0;
		    	break;
		    }
	    }
	    sort(b,b+j);
		    long long max2=0;
		    for(int t=0;t<j;t++){
		    	if(max2>m){
		    		break;
				}
				max2+=b[t];
			}
			if(j>max1){
				max1=j+1;
			}
		}
	cout<<max1-1;
	return 0;
	
}
