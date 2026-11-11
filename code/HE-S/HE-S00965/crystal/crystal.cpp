#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ping;
vector<long long>a;
int main(){
	cin>>n>>m;
	long long sum=0;
	for (int i=0;i<n;i++){
		long long q;
		cin>>q;
		a.push_back(q);
		sum+=a[i];
	}
	if(n>2){
	    sum-=a[0];
	    sum-=a[n-1];
	    ping=sum/(n-2);
    }else{
    	ping=sum/n;
	}
	sort(a.begin(),a.end());
	int xia;
	for(int i=0;i<n;i++){
		if(a[i]>ping){
			xia=i;
			break;
		}
	}
	
	//数组内容输出 
	//for(int i=0;i<n;i++) cout<<a[i]<<' '; cout<<endl; cout<<xia<<endl;cout<<ping<<endl;
	
	for(int i=xia-1;i>=0;i--){
		if(m>0) {
        while(a[i]!=a[xia]){
        	a[i]++;
        	m--;
		    }
	    }
	}
	
	//更新后数组内容输出 
	//for(int i=0;i<n;i++) cout<<a[i]<<' '; cout<<endl;
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[xia]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
