#include<bits/stdc++.h>
using namespace std;
long long a[200005],b,c,m=-9999999;
bool w[200005]={0};
void qwe(int k,long long s){
	cout<<"s"<<s<<endl;
	if(k==c+1){
		m=max(m,s);
		return ;
	}
	for(int i=1;i<=b;i++){
		if(w[i]==0){
			w[i]=1;
			cout<<s<<" "<<a[i];
			if(s==0){
				qwe(k+1,a[i]);
			}else{
				qwe(k+1,s and a[i]);
			}
			w[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	qwe(1,0);
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
