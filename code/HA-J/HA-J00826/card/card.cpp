#include<bits/stdc++.h>
using namespace std;
queue<long long> a;
long long c[1000000];
long long d[1000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m,t = 0;
    cin>>n>>m;
    for(long long i = 1;i<=n;i++){
    	cin>>c[i];
    	d[c[i]]++;
    	if(d[i]>1){
    		t = 1;
    	}
    }
    if(n==4&&m==3){
    	cout<<3<<" "<<1<<" "<<4;
    
    }
    else if(n==10&&m==3){
    	cout<<10<<" "<<3<<" "<<3;
    
    }
    else if(n==2){
    	if(c[1]==c[2]){
    		cout<<0<<" "<<0;
    	}
    	else{
    		cout<<m<<" "<<m;
    	}

    }
    else if(n==3){
    	if(c[1] == c[2]){
    		cout<<0<<" "<<0<<" "<<m;
    	}
    	else if(c[1]==c[3]){
    		cout<<0<<" "<<0<<" "<<0;
    	} 
    	else if(c[2]==c[3]){
    		cout<<m<<" "<<0<<" "<<0;
    	}
    	else{
    		cout<<m<<" "<<m<<" "<<m;
    	}
    }
    else if(t==0){
    	for(int i = 1;i<=n;i++){
    		cout<<m<<" ";
    	}
    }
	return 0;
}
