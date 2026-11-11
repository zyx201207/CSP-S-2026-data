#include<bits/stdc++.h>
using namespace std;
const int N=500007;
long long n,m,a[N],s,a1[N],a2[N],w;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
    	for(int l=i;l<=n;l++){
		    for(int j=2;j<=s;j++){
			    if(a[l]==a1[j]){
				    w=j;
				    break; 
			    }
			    else{
			    	s=0;
				}
	        }
		    for(int j=w;j<=s;j++){
		    	a1[j]=0;
		    }
		    if(s>=w&&s>0){
		        s-=w-1;
			}
	    	s++;
		    a1[s]=a[l];
	    }
	    for(int j=1;j<=s;j++){
	    	a2[a1[j]]++;
		}
    }
    for(int i=1;i<=m;i++){
    	if(a2[i]!=0){
		    cout<<a2[i];
		}
	}
	return 0;
} 
