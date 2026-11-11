#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],sum,h;
char c[200001],q,f;
void z(int i,int j,char k,char o,int num){
	h = i-j;
	q = k;
	f = o;
	sum += num;
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> c[i];
	}
	bool pan = true;
	long long left = 0,right = n-1;
	while(left < right){
		if(pan == true){
			if(c[left] == c[right]){
				if(a[left] == a[right]){
					left++;
					right--;
				}else if(a[left] > a[right]){
					pan = false;
					z(a[left],a[right],c[left],'l',0);
					right--;
				}else{
					pan = false;
					z(a[right],a[left],c[right],'r',0);
					left++;
				}
			}else{
				if(a[left] != a[right]){
					if(a[left] > a[right]){
						pan = false;
						z(a[left],a[right],c[left],'l',a[right]);
						right--;
					}else{
						pan = false;
						z(a[right],a[left],c[right],'r',a[left]);
						left++;
					}
				}else sum += a[left];
			}
		}else{
			if(f == 'l'){
				if(c[right] != q){
					if(a[right] == h){
						sum += a[right];
						right--;
						left++;
						pan = true;
					}else if(h > a[right]){
						z(h,a[right],q,f,a[right]);
						right--;
					}else{
						z(a[right],h,c[right],'r',h);
						left++;
					}
				}else{
					if(a[right] == h){
						pan = true;
						right--;
						left++;
					}else if(a[right] < h){
						z(h,a[right],q,f,0);
						right--;
					}else{
						z(a[right],h,c[right],'r',0);
						left++;
					}
				}
			}else{
				if(c[left] != q){
					if(a[left] == h){
						pan = true;
						left++;
						right--;
						sum += h;
					}else if(a[left] > h){
						z(a[left],h,c[left],'l',h);
						right--;
					}else{
						z(h,a[left],q,f,a[left]);
						left++;
					}
				}else{
					if(a[left] == h){
						pan = true;
						left++;
						right--;
					}else if(a[left] > h){
						z(a[left],h,c[left],'l',0);
						right--;
					}else{
						z(h,a[left],q,f,0);
						left++;
					}
				}
			}
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
