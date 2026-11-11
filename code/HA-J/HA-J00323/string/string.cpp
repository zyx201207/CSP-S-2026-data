#include<bits/stdc++.h>
using namespace std;

int n;
long long res;
struct Node{
	int x;
	char c;
}A[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i].x>>A[i].c;
	}
	int l=1,r=n;
	while(1){
		if(l>r){
			break;
		}
		if(A[l].c!=A[r].c){
			if(A[l].x<A[r].x){
				res+=A[l].x;
				A[r].x-=A[l].x;
				l++;
			}else if(A[l].x>A[r].x){
				res+=A[r].x;
				A[l].x-=A[r].x;
				r--;
			}else{
				res+=A[l].x;
				l++;
				r--;
			}
		}else{
			if(A[l].x<A[r].x){
				A[r].x-=A[l].x;
				l++;
			}else if(A[l].x>A[r].x){
				A[l].x-=A[r].x;
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<res;
}
