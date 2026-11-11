#include<bits/stdc++.h>
using namespace std;
struct note{
	long long detal, to;
	bool operator<(note other) const{
		return detal<other.detal;
	}
}b[500005];
long long n, m, a[500005], pos = 0, hashnum[500005], hash1[500005], thas = 1, ans = 0, lpos = 0, lnum = 0, ltnum = 0, llnum = -1, use1, length1, tdetal = 0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//cout<<"a\n";
	scanf("%lld %lld", &n, &m);
	//cout<<n<<" "<<m<<"a\n";
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	//cout<<"a\n";
	sort(a+1, a+n+1);
	//cout<<"a\n";
	//for(int i = 1;i<n;i++){
		//cout<<i<<" "<<a[i]<<"\n";
		
	//}
	for(int i = 1;i<=n;i++){
		if(a[i+1]==a[i]){
			thas++;
		}else{
			b[pos].to = i;
			hash1[pos] = thas;
			hashnum[pos] = thas;
			if(i!=n)b[pos++].detal = a[i+1]-a[i];
			else b[pos++].detal = 0;
			//cout<<" a"<<b[pos-1].to<<" "<<b[pos-1].detal<<" "<<hash1[i]<<endl;
			thas = 1;
		}
		
	}
	//for(int i = 0;i<pos;i++){
		//if(b[i].detal!=1)cout<<"c";
		//cout<<i<<" "<<b[i].to<<" "<<b[i].detal<<" "<<hash1[b[i].to]<<endl;
	//}
	//cout<<pos;
	length1 = ans = hash1[0];
	/*for(int i = 0;i<pos;i++){
		
		use1+=length1*(b[i].detal);
				
		length1+=hash1[i+1];
		cout<<i<<" "<<use1<<" "<<hash1[i]<<" "<<hash1[i+1]<<" "<<length1<<" ";
		if(use1>m){
			
				ltnum = a[b[i].to+1]-a[b[lpos].to];
				int tmp = min(lnum, (use1-m+ltnum-1)/ltnum);
				length1-=tmp;
				lnum -= tmp;
				use1-=ltnum*tmp;
				if(lnum==0)lpos++;
				else{
					llnum = lpos;
				}
				cout<<"a ";
			
		}
		while(lpos<i&&(a[b[i].to+1]-a[b[lpos].to])*hashnum[lpos]<=use1-m){
			use1-=(a[b[i].to+1]-a[b[lpos].to])*hashnum[lpos];
			length1-=hashnum[lpos];
			lpos++;
			cout<<"b ";
		}
		if(use1>m){
			cout<<"c "<<lnum<<" " <<lpos<<" "<<hashnum[lpos]<<" ";
			if(llnum!=lpos||lnum == 0)lnum = hashnum[lpos];
			cout<<lnum<<" ";
			ltnum = a[b[i].to+1]-a[b[lpos].to];
			lnum -= ((use1-m+ltnum-1)/ltnum);
			
			length1-=((use1-m+ltnum-1)/ltnum);
			cout<<(use1-m+ltnum-1)/ltnum<<" "<<ltnum<<" ";
			use1-=(ltnum)*((use1-m+ltnum-1)/ltnum);
			
		}	

		ans = max(ans, length1);
		cout<<hash1[i]<<" "<<hash1[i+1]<<" "<<length1<<" "<<use1<<endl;
	}*/
	ans = length1 = 1;
	for(int i = 2;i<=n;i++){
		
		
		if(a[i]!=a[i-1]){
			use1+=length1*(a[i]-a[i-1]);
			//cout<<i<<" "<<use1<<" "<<length1<<endl;
			while(lpos<i&&use1>m){
				use1-=a[i]-a[lpos++];
				length1--;
			}
		}
		length1++;
		ans = max(ans, length1);
	}
	cout<<ans;
	return 0;

}
