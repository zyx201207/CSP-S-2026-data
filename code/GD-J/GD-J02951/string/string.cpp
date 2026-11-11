#include<bits/stdc++.h>
using namespace std;
struct box{
	long long start,end;
	char m;
};

int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<box> a(n+1);
	long long cnt=1;
	for(long long i=1;i<=n;i++){
		long long lo;
		cin>>lo;
		a[i].start=cnt;
		cnt=a[i].start+lo;
		a[i].end=cnt-1;
		cin>>a[i].m;
	}

	long long middle;
	if(cnt%2==0){
        middle=cnt/2;
    }else{
        middle=cnt/2+1;
    }

    long long l,r;
    long long ans=0;
    long long num=1;
    l=1;r=n;
    for(long long i=1;i<=middle;i++){
    	if(a[l].end < i){
    		l+=1;
		}
		if(a[r].end > cnt-i+1){
    		r-=1;
		}
        if(a[l].m != a[r].m){
            ans++;
        }
    }
    cout<<ans;
	return 0;
}

