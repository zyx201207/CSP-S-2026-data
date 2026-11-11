#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt,sh,all;
long long a[114514];
char b[114514];
char found(int t){
	for(int i=1;i<=sh;i++){
		if(t-a[i]>0){
			t-=a[i];
		}else{
			return b[i];
		}
	}
}
long long zz(long long a,long long b){
	if(b==0) return a;
	return zz(b,a%b);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long t1;
	char t2;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		if(t2==b[sh]){
			a[sh]+=t1;
		}else{
			sh++;
			a[sh]=t1;
			b[sh]=t2;
		}
	}
	long long cf=a[1];
	for(int i=2;i<=sh;i++){
		cf=zz(cf,a[i]);
	}
	for(int i=1;i<=sh;i++){
		a[i]/=cf;
		all+=a[i];
	}
	//cout<<cf<<" ";
	//cout<<sh;
	cnt=all/2;
	int p=cnt;
	//cout<<a[1]<<" "<<a[2]<<" "<<all;
	for(int i=1;i<=p;i++){
		if(found(i)==found(all-i) && all%2!=0 || found(i)==found(all-i+1) && all%2==0) cnt--;
		//cout<<found(i);
	}
	cout<<cnt*cf;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
