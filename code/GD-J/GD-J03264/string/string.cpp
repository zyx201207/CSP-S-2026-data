#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10,N=1e9+10;
int nums[MAXN*2];
char let[MAXN*2];
char l[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	bool bl=true;
	long long mid=0,num=0,f=0;
	for(int i=1;i<=n;i++){
		cin>>nums[i]>>let[i];
		if(nums[i]<=100000000){
			mid+=nums[i];
			for(int j=f+1;j<=f+nums[i];j++){
				l[j]=let[i]; 
			}
			f+=nums[i];
		}else{
			bl=false;
		}
	}
	long long t1=1,t2=f;
	if(bl==false){
		t2=n;
		while(t2-t1>=1){
			if(let[t1]!=let[t2]&&nums[t1]==nums[t2]){
				num+=nums[t1];
			}
			t1++;
			t2--;
		}
	}
	else{
		while(t2-t1>=1){
		if(l[t1]!=l[t2]){
			num++;
		}
		t1++;
		t2--;
	}
	}
	cout<<num;
	return 0;
}
