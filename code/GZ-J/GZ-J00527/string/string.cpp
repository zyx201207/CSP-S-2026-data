//GZ-J00527 谢明泽 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],su=0,an = 0,yy;
string ss;
char ai[200005];
bool tp[27];
void sreach(int h){
	if(h % 2 == 1){
		long long mid = (h+1)/2,cs = (h-1)/2;
		long long l = mid -2,r = mid ;
		for(int i = 0;i<cs;i++){
			if(ss[l] != ss[r]) an++;
			l--;
			r++;
		}
	}
	else{
		long long mid = h/2,cs = h/2;
		long long l = mid -1,r = mid ;
		for(int i = 0;i<cs;i++){
			if(ss[l] != ss[r]) an++;
			l--;
			r++;
		}	
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> ai[i];
		su+=a[i];
		tp[int(ai[i]) - 96] = 1;
		for(int j = 0;j<a[i];j++){
			ss += ai[i];
		}
	}
	for(int i = 1;i<=26;i++){
		if(tp[i]){
			yy++;
		}
	}
	if(yy==1){
		cout << 0;
		return 0;
	}
	sreach(su);
	cout << an;
	cout << int('a');
	return 0;
}
