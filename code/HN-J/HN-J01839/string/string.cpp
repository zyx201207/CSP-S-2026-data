#include<bits/stdc++.h>
using namespace std;

//Trick||Treat!
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	unsigned long long sum=0;
	int n;
	cin>>n;long long q;char a1;
    vector<char> a;vector<long long>b;
    for(int i=0;i<n;i++){
    	cin>>q>>a1;
    	b.push_back(q);
		a.push_back(a1);
	}
	for(int i=0,q=n;i<q;){
			if(b[i]>b[q]) {
				if(a[i]!=a[q])
					sum+=b[q];
				b[i]-=b[q],	q--;	
			}
			else if(b[i]<b[q]){
				if(a[i]!=a[q]){
					sum+=b[i];
				}
				b[q]-=b[i],i++;
			}
			else {
				if(a[i]!=a[q])
				sum+=b[i];
				i++,q--;
			}	
	}
	cout<<sum;
	}
