//GZ-J00690   öÄ²Åº­ 
#include <bits/stdc++.h>
using namespace std;

bool hw(string a){
	int len=a.size();
	
	for(int i=0;i<(len/2);i++){
		if(a[i]!=a[len-i-1]) return false;
	}
	return true;
}

int same(string a){
	int len=a.size(),sum=0;
	
	for(int i=0;i<(len/2);i++){
		if(a[i]==a[len-i-1]) sum++;
	}
	
	return sum;
}


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	string a,temp,b;
	long long n,m,alen=0,blen=1;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> m;
		cin >> temp;
		for(int j=1;j<=m;j++){
			a+=temp;
		}
	}
	
	if(hw(a)){
		printf("0");
	}else{
		printf("%d",(a.size()-same(a))/2);
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
