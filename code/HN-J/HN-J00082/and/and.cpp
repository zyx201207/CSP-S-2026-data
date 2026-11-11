#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","W",stdout);

	int n,m;
	cin >> n >> m;
	long long aa[200005];
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
    sort(aa,aa+n);
    int bb[200002]={0};
	for(int i=n;i>1;i--){
		bb[aa[i]]++;
	}
	unsigned long long j=67679178,z=0;
	for(int i=n;i>1;i--){
		if(bb[i]>2 and i>z){
			j=bb[i];z=i;
		}
	}
	if(z<bb[aa[n]]){
		cout<<n;
	}
	else{
		cout<<aa[n];
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
