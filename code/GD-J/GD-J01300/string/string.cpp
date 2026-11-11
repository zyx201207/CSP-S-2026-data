#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<int> a;
	vector<char> b;
	int n;
	cin>>n;
	int e=0;
	for(int i=0;i<n;i++){
		int q;
		char w;
		cin>>q>>w;
		e+=q;
		a.push_back(q);
		b.push_back(w);
		
	}
	int sum=0,c=0;
	char d;
	for(int i=0;!(e<=1);i++){
		int l=0;
		if(c!=0){
			if(l==0){
				if(c>a[n-i-1]&&d!=b[n-i-1]){
					sum+=a[n-i-1];
					l=0;
					c-=a[n-i-1];
					e-=2*a[n-i-1];
				}
				else{
					sum+=c;
					a[n-i-1]-=c;
					d=b[n-i-1];
					l=1;
					c=0;
					e-=2*c;
				}
			}
			else{
				if(c>a[i]&&d!=b[i]){
					sum+=a[i];
					l=1;
					c-=a[i];
					e-=2*a[i];
				}
				else{
					sum+=c;
					a[i]-=c;
					d=b[i];
					l=0;
					c=0;
					e-=2*c;
				}
			}
		}
		if(i==n-i-1){
			e=1;
			break;
		}
		if(c==0){
			if(a[i]>a[n-i-1]&&b[i]!=b[n-i-1]){
			sum+=a[n-i-1];
			c=a[i]-a[n-i-1];
			d=b[i];
			l=0;
			e-=2*a[n-i-1];
		}
		   if(a[n-i-1]>=a[i]&&b[i]!=b[n-i-1]){
			sum+=a[i];
			c=a[n-i-1]-a[i];
			d=b[n-i-1];
			l=1;
			e-=2*a[i];
		 }
		}
	}
	cout<<sum;
	return 0;
}
