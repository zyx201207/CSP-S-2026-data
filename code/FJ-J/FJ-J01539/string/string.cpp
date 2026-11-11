#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt,n,d;
string c[200005],l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			l+=c[i];
		}
	}
	int cnt=0;
	d=l.size();
	if(d%2==1){
	    for(int i=1;i<=d;i++){
	    	if(i=d){
	    		break;
	    	}
		    if(l[i]==l[d]){
		    	d-=1;
		    }
		    if(l[i]!=l[d]){
		    	d-=1;
			    cnt+=1;
		    }
	    }	
    }
    if(d%2==0){
	    for(int i=1;i<=d;i++){
	    	if(i=d+1){
	    		break;
	    	}
		    if(l[i]==l[d]){
		    	d-=1;
		    }
		    if(l[i]!=l[d]){
		    	d-=1;
			    cnt+=1;
		    }
	    }	
    }
    cout<<cnt;
	return 0;
}
