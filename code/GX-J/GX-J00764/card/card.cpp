#include<bits/stdc++.h>
using namespace std;
int n,a[1919810],ans,l=1,r=1,table[1919810],m;
void take(int p){
	table[r]=p;
	r++;
	return;
}	
int find(int k){
	for(int i=l;i<=r;i++){
		if(table[i]==k){
			return i;
	    }	
    }	
    return -1;
}	
void throwcard(int x){
	r=x-1;
	return;
}	
void tableclean(){
	l=1;
	r=1;
	table[l]=0;
	return;
}	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	vector<int> sum(m);
	for(int i=1;i<=n;i++){
		cin >> a[i];
    }
    for(int game=1;game<=n;game++){
		tableclean();
        for(int i=game;i<=n;i++){
		    int f=find(a[i]);
	        if(f>=1){
			    throwcard(f);
			    take(a[i]);
			    continue;
	        }	
	        else if(f==-1){
			    take(a[i]);
	        }	
        }	
        for(int b=1;b<m;b++){
			for(int i=l;i<=r;i++){
			    if(table[i]==b){
				    sum[b]++;
		        }	
	        }
	    }	
    }
    for(int i=0;i<m;i++){
		cout << sum[i] << ' ';
    }	
    return 0;
}	
