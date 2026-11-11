#include<bits/stdc++.h>
using namespace std;
long long a[210000010];
char a2[2100000010];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n , m , sum = -1 , now , sum1 = 0 , fac = 1;
    for(int i = 1 ; i <= n ; i++)
    {
	cin >> a[i];
    }
    for(int i = n ; i <= n ;i++){
        while(a[i] > 0){
            a2[i] += a[i] % 2;
            a[i] /=2;
            a2[i] *= 10;}}
    if(m == 1){
        for(int i = 1 ; i <= n ; i++){
	    now = a2[i];
	}
    }
    if(m == 2){
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(i != j)
                {
                    now = a2[i] & a2[j];
                    sum = max(sum , now);
		}
	    }
	}
    }
    if(m == 3){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 1 ; k <= n ; k++){
                    if(i != j && i != k && j != k){
                        now = a2[i] & a2[j] & a2[k];
                        sum = max(sum , now);}}}}}
    if(m == 4){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 1 ; k <= n ; k++){
                    for(int l = 1 ; l <= n ; l++){
                        if(i != j && i != k && j != k && i != l && j != l && k != l){
                            now = a2[i] & a2[j] & a2[k] & a2[l];
                            sum = max(sum , now);}}}}}}
    if(m == 5){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 1 ; k <= n ; k++){
                    for(int l = 1 ; l <= n ; l++){
                        for(int o = 1 ; o <= n ; o++){
                            if(i != j && i != k && j != k && i != l && j != l && k != l && i != o && j != o && k != o && l != o){
                                now = a2[i] & a2[j] & a2[k] & a2[l] & a2[o];
                                sum = max(sum , now);}}}}}}}
    while(sum > 0){
        for(int i = 0 ; i <= sum ; i++){
            sum1 += sum % 10 * fac;
            fac *= 2;
            sum /= 10;}}
    for(int i = 1 ; i <= n ; i++)
    {
		cout << sum1;
    }
    return 0;
}
