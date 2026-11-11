
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    unsigned int n;
    cin>>n;
    unsigned long long ll[200005];
    char cc[200005];
    for(int i=0;i<n;i++){
    	cin>>ll[i];
	   	cin>>cc[i];
			if(cc[i-1]==cc[i]){
				ll[i-1]=ll[i-1]+ll[i];
				n--;
				i--;
			}
	}
	int l=0,r=n;
	unsigned long long i=0;
	for(int j=0;j<n;j++){
		if(ll[j]%2==0){
			i=i+ll[j]/2;
		}
	}
    cout << i;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
