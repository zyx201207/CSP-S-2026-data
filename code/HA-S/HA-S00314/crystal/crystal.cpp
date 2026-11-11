//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);


	
	int n,m;
	int ans=0;
	cin>>n>>m;
	int iner;
	
	int a[99999];

	for(int i=1;i<=n;i++){
		cin>>a[i];

		} 
	
	int count_=0;
	sort(a+1,a+n);

	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
            a[i+1]+=a[i];
            if (a[i+2]!=0) swap(a[i+1],a[i+2]);
            ans++;
            count_++;
            continue;
		}
        if(count_>=m || a[i+1]==0) break;

		while(1){
            if(count_>=m || a[i+1]==0) break;
            count_++;
            a[i]++;
            
            
            if(a[i]==a[i+1]){
                a[i+1]+=a[i];
                if (a[i+2]!=0) swap(a[i+1],a[i+2]);
                ans++;
                count_++;

                break;}
		}

		
	}
	cout<<ans;
//	while(count_<m){
//
//	}
	return 0;
}
