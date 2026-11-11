#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
long long m;
int q[N];
int mx,mid,m1;
//vector <int> v[N];
bool cmp(int x, int y){
	return x>y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	
	int res=0;
	sort(q,q+n,cmp);
	
	/*
	for(int i=0;i<n;i++){
		int x=i;
		mx=max(mx,q[i]);
		mid=mx-n;
		
		if(q[i]==mid){
			res++; 
		}
		
		v[i].push_back(mid-q[i]);
		
	}
	
	res++;
	sort(v,v+n);
	*/
	
	for(int i=0;i<n;i++){
		mid=q[i];
		if(mid>=n/2){
			q[++i];
			m1+=1;
		}
			
		res++;
		if(m1==m){
			break;
		}
		
		
	}
	mx=max(mx,res);

	/*
	while(m--){
		for(int i=0;i<n;i++){
			q[++i];
		}
	}
	*/
	cout<<mx<<endl;
	return 0;
}
