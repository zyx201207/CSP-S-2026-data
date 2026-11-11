#include<bits/stdc++.h>
using namespace std;
const int MOD=100000005;
char ans[MOD],l[MOD],r[MOD];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	long long n,cnt=0;
	cin>>n;
	while(n--){
	    long long a;
	    string d;
		cin>>a>>d;
		while(a--){
			ans[cnt]=d[0];
			cnt++;
		}
	}
	if(cnt%2==0){
		for(int i=0;i<cnt/2;i++){
		    l[i]=ans[i];
	    }
	    long long mm=0;
	    for(int i=cnt/2+1;i<=cnt;i++){
		    r[mm]=ans[i];
		    mm++;
	    }
	    long long sum=0;
	    for(int i=0;i<cnt/2;i++){
	    		if(r[i]<l[i]||r[i]>l[i]){
	    		sum++;
	    	}
	    	
	    }
	    cout<<sum;
	}else{
		for(int i=0;i<ceil(cnt/2);i++){
			l[i]=ans[i];
		}
		long long nn=0;
		for(int i=ceil(cnt/2);i<=cnt;i++){
			r[nn]=ans[i];
			nn++;
		}
		long long nnum=0;
		for(int i=0;i<ceil(cnt/2);i++){
				if(r[i]<l[i]||r[i]>l[i]){
				nnum++;
			}
		}
		cout<<nnum;
	}
	return 0;
}
