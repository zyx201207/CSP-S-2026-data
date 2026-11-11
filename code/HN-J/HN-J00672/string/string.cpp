#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
	cin>>n;
	int a;
	char zm;
	int x=0;
	char zi[200001];
	for(int i=0;i<n;i++){
		cin>>a>>zm;
		for(int j=0;j<a;j++){
			zi[x]=zm;
			x++;
		}
	}
	char iz[200001];
	int cnt=0;
	for(int i=0;i<200001;i++){
		if(zi[i]>=97){
			cnt++;
		}
	}
	int z=cnt;
	cnt--;
	for(int i=0;i<z;i++){
		iz[i]=zi[cnt];
		cnt--;
	}
	cnt=0;
	for(int i=0;i<z;i++){
		if(iz[i]!=zi[i]){
			cnt++;
		}
	}
	cnt/=2;
	cout<<cnt;
    return 0;
}
