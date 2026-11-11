#include<bits/stdc++.h>
using namespace std;
long long n;
long long truE;
long long a[50020];
int main(){
	 freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>truE;
    for(int l=1;l<=n;l++){
        cin>>a[l];
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

	int c=0;

	int t=1;
	while(true){
		if(a[t]<a[t+1]&&c<truE){
            c++;
            a[t]++;
            if(a[t]==a[t+1]){
                t++;

            }
		}else if(c==truE){
		    break;
		}
	}
	cout<<t;
	return 0;
}

