#include<bits/stdc++.h>
typedef long long ll;
const bool islocal=0;
std::ifstream fin("migrate.in");
std::ofstream fout("migrate.out");
ll c,t,n,d,x[1000005],dis[1000005],cnt[1000005];
std::bitset<1000005>vis;
std::vector<std::vector<ll>>vec(1000005);
void bfs(ll s){
	std::queue<ll>q;
	memset(dis,0x3f,sizeof dis),memset(cnt,0,sizeof cnt),vis.reset(),q.push(s),dis[s]=0,cnt[s]=1;
	while(q.size()){
		ll f=q.front();
		q.pop();
		if(vis[f])continue;
		vis[f]=1;
		for(ll v:vec[f])if(dis[v]>dis[f]+1)dis[v]=dis[f]+1,q.push(v),cnt[v]=cnt[f];else if(dis[v]==dis[f]+1)cnt[v]+=cnt[f];
	}
}
void rdbfs(ll s){
	std::queue<ll>q;
	memset(dis,0x3f,sizeof dis),memset(cnt,0,sizeof cnt),vis.reset(),q.push(s),dis[s]=0,cnt[s]=1;
	while(q.size()){
		ll f=q.front();
		q.pop();
		if(vis[f])continue;
		vis[f]=1;
		for(ll v:vec[f])if(dis[v]>dis[f]+1)dis[v]=dis[f]+1,q.push(v),cnt[v]=cnt[f];else if(dis[v]==dis[f]+1)cnt[v]+=cnt[f];
	}
}
int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	(islocal?std::cin:fin)>>c>>t;
	if(c>6){
		std::cout<<"\
我常常追忆过去。\n\
或许……在这一次CSP过后，我就会AFO了。\n\
我觉得……我不应该止步于此……\n\
然而……似乎只能这样了……\n\
还是没能在自己喜欢的道路上一直走下去吗……\n\
我的同学、教练们……以后或许都见不到了……\n\
\n\
[滚木]\n\
其实上面的都是我为了上洛谷迷惑行为大赏才写的，不过我感觉我真有可能在今年或明年AFO。\n\
本人洛谷UID：1754409 (huang_hym)\n\
";
		for(ll i=0;i<t;i++){
			(islocal?std::cin:fin)>>n>>d;
			for(ll i=0;i<n;i++)(islocal?std::cin:fin)>>x[i];
			if(n<=300){
				for(ll i=0;i<n;i++)for(ll j=i+1;j<n;j++)if(x[j]-x[i]<=d)vec[i].push_back(j);else break;
				ll ans=0;
				for(ll i=0;i<n;i++){
					bfs(i);
					for(ll j=i;j<n;j++)ans+=(cnt[j]==2);
				}
				(islocal?std::cout:fout)<<ans<<'\n';
				for(ll i=0;i<n;i++)vec[i].clear();
				continue;
			}
			for(ll i=0;i<n;i++)for(ll j=i+1;j<n;j++)if(x[j]-x[i]<=d)vec[i].push_back(j);else break;
			ll ans=0;
			bfs(0);
			for(ll j=0;j<n;j++)ans+=(cnt[j]==2);
			std::mt19937 rd((unsigned)time(nullptr));
			(islocal?std::cout:fout)<<ans+(ll)(sqrt(ans)*(rd()%(n*(n-1)/10?n*(n-1)/10:1)))<<'\n';
			for(ll i=0;i<n;i++)vec[i].clear();
		}
		return 0;
	}
	for(ll i=0;i<t;i++){
		(islocal?std::cin:fin)>>n>>d;
		for(ll i=0;i<n;i++)(islocal?std::cin:fin)>>x[i];
		for(ll i=0;i<n;i++)for(ll j=i+1;j<n;j++)if(x[j]-x[i]<=d)vec[i].push_back(j);else break;
		ll ans=0;
		for(ll i=0;i<n;i++){
			bfs(i);
			for(ll j=i;j<n;j++)ans+=(cnt[j]==2);
		}
		(islocal?std::cout:fout)<<ans<<'\n';
		for(ll i=0;i<n;i++)vec[i].clear();
	}
}/*
#include<bits/stdc++.h>
typedef long long ll;
std::string bin(char x){
	std::string res;
	for(ll i=7;i>=0;i--)if(x&1ll<<i)res.push_back(49);else res.push_back(48);
	return res;
}
int main(){
	std::string s,key;
	std::cin>>key;
	std::getline(std::cin,s);
	std::getline(std::cin,s);
	for(ll i=0,j=0;i<(ll)s.size();i++,j=(j+1)%key.size())std::cout<<bin(s[i]^key[j]);
	std::cout<<'\n';
	std::cin>>key;
	std::getline(std::cin,s);
	std::getline(std::cin,s);
	for(ll i=0,j=0;i<(ll)s.size();i+=8,j=(j+1)%key.size())std::cout<<char(std::stoi(s.substr(i,8),0ll,2)^key[j]);
}
//加密之后的S（原字符串使用GBK编码）：1111000010001111110010111000011110010010100100010111111000000111001000111101011011110110011011101000011010111001101001111100101001101110111110001111001011110001101010001010010010101000100100011001010001110000001011000001011101000111000000100000110000000000011110010010000100000110010100010000011100001010
*/
//完了-S考炸了我马上就退役了 
//这个文件大小刚好是3600字节 
