//Warning ! There are something my telling under this cpp .
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+1;
const int MIN=1e12;
const int MAX=1e18;
int a[N],maxn,minn=MIN,n,m,bj[500001],js[500001];
queue<int>q;
void half(int l,int r){
	if(l>=r||l+1==r){
		if(bj[l]>bj[r]) swap(bj[l],bj[r]);
		return ;
	}
	int mid=(l+r)>>1;
	half(l,mid),half(mid+1,r);
	int k=0;
	for(int l1=l,r1=mid+1;l1<=r1;){
		if(r1>r){
			for(int i=l1;i<=mid;i++) js[(k++)+l]=bj[i];
			break;
		}
		if(l1>mid){
			for(int i=r1;i<=r;i++) js[(k++)+l]=bj[i];
			break;
		}
		if(bj[l1]<bj[r1]) js[(k++)+l]=bj[l1++];
		else js[(k++)+l]=bj[r1++];
	}
	for(int i=l;i<=r;i++) bj[i]=js[i];
}
int check(int x){
	memset(bj,0,sizeof bj),memset(js,0,sizeof js);
	for(int i=1;i<=n;i++){
		if(a[i]>x) bj[i]=MAX;
		else{
			bj[i]=x-a[i];
		}
	}
	half(1,n);
	int cnt=0,m1=m;
	for(int i=1;i<=n;i++){
		if(m1-bj[i]>=0) cnt++,m1-=bj[i];
	}
	return cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	int l=minn,r=maxn;
	maxn=0;
	while(l<=r){
		int mid=(l+r-1)/2,sum=check(mid);
		if(sum>maxn) maxn=sum,l=mid+1;
		else r=mid-1;
	}
	cout<<maxn;
	return 0;
}
/*
I wanted to tell somethings about the CSP-S
(1)I'm a Grade 7 student , in this test I find that I'm small . When I was thinking , the students in the second class are typing
   their cpp . In fact , They are all clever . I had some emergency , so I'm in CSP-S
(2)that not well:

first I taked 2 hours to do this work
second this works is taked to me because the {
1.- #include<bits/stdc++.h> changed to #include<bits\stdc++.h> , in Windows , it well . But in NOI Linux is not well
2.- freopen("crystal.in","r",stdin); and freopen("crystal.out","w",stdout);
	changed to freopen("crystal.in",'r',stdin); and freopen("crystal.out",'w',stdout);
	this mistake takes me 10 mins.So I'm angry.
3.- the middle fen(it is Chinese) , I have a emergency , I taked 20 mins , Time fies!
4.- the function of half is Wrong because "int" changed "bool" , it taked me 20 mins! (I'm the second in the mistake)
5.- Scanning for this cpp , I find a mistake , it taked me 3 mins.
I thought this take 50 mins.
}
*/
