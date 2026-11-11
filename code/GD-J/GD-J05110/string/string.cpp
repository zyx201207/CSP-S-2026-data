#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=1,sum=0,max=0;
    string p[100000]; 
    cin>>n;
    for(int i=1;i<=n;i++){
    	int a;
    	string b;
    	cin>>a>>b;
    	max+=a;
    	for(int i=1;i<=a;i++){
    		p[num]=b;
    		num++;
		}
	}
	for(int i=1;i<=num-1;i++){
		
		if(p[i]!=p[max]){
			sum++;
		}
	}
	cout<<sum/2;
}
