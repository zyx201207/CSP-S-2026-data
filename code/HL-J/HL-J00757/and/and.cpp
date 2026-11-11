#include <bits/stdc++.h>
using namespace std;

int n,m,a[2e5+5],x,y;

bool asd(int k){
	int i=0;
	while(i+1){
		if(pow(2,i)>y+1){
			return false;
		}
		if(y+1==pow(2,i)){
			return true;
		}
		i++;
	}
	return 0;
}
bool check(int i,int j){
	int s1,s2;
	while(i){
		s1+=i%2;
		i/=2;
	}
	while(j){
		s2+=j%2;
		j/=2;
	}
	return s1>=s2;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin<<a[i];
		y=max(a[i],y);
		if(a[i]>x&&check(a[i],x)){
			x=a[i];
		}	
	}
	sort(a,a+n);
	if(a[n-m-1]==0){
		cout<<0;
	}else if(asd(y)){
		cout<<y;
	}else{
		cout<<x;
	}
    return 0;
}
